
#pragma once

#include <vector>

#include "common/internal_types.hpp"
#include "common/types/vector.hpp"

#define STANDARD_VECTOR_SIZE 1024

namespace duckdb {
class DataChunk {
  public:
	oid_t count;
	oid_t column_count;
	std::unique_ptr<Vector> *data;
	oid_t maximum_size;
	std::unique_ptr<sel_t[]> sel_vector;

	DataChunk();
	~DataChunk();

	void Initialize(std::vector<TypeId> &types,
	                size_t maximum_chunk_size = STANDARD_VECTOR_SIZE);
	void Append(DataChunk &other);
	void Clear();

	void Reset();
};
}
