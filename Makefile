all:

heap: lets_make_a_heap.cpp
	clang++ -o heap lets_make_a_heap.cpp

sort: lets_sort_stuff.cpp
	clang++ -o sort lets_sort_stuff.cpp

bloom filter: lets_make_a_bloom_filter.cpp
	clang++ -o bloom_filter lets_make_a_bloom_filter.cpp

hash: lets_make_a_hash_table.cpp
	clang++ -o hash_table lets_make_a_hash_table.cpp

linear probe hash: lets_make_another_hash_table.cpp
	clang++ -o linear_probe_hash_table lets_make_another_hash_table.cpp