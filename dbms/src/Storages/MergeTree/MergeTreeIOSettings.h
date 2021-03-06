#pragma once
#include <cstddef>
#include <Core/Settings.h>

namespace DB
{

struct MergeTreeReaderSettings
{
    size_t min_bytes_to_use_direct_io = 0;
    size_t min_bytes_to_use_mmap_io = 0;
    size_t max_read_buffer_size = DBMS_DEFAULT_BUFFER_SIZE;
    /// If save_marks_in_cache is false, then, if marks are not in cache, 
    ///  we will load them but won't save in the cache, to avoid evicting other data.
    bool save_marks_in_cache = false;
};

struct MergeTreeWriterSettings
{
    MergeTreeWriterSettings(const Settings & global_settings, bool can_use_adaptive_granularity_,
        size_t aio_threshold_, bool blocks_are_granules_size_ = false)
        : min_compress_block_size(global_settings.min_compress_block_size)
        , max_compress_block_size(global_settings.min_compress_block_size)
        , aio_threshold(aio_threshold_)
        , can_use_adaptive_granularity(can_use_adaptive_granularity_)
        , blocks_are_granules_size(blocks_are_granules_size_) {}

    size_t min_compress_block_size;
    size_t max_compress_block_size;
    size_t aio_threshold;
    bool can_use_adaptive_granularity;
    bool blocks_are_granules_size;
    /// true if we write temporary files during alter.
    bool is_writing_temp_files = false;
    size_t estimated_size = 0;
    /// used when ALTERing columns if we know that array offsets are not altered.
    bool skip_offsets = false;
};
}
