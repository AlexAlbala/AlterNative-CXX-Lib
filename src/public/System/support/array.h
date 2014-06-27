#pragma once
#define CREATE_MD_ARRAY(arr, ...) arr(boost::extents##[##__VA_ARGS__##] )
#define GET_MD_ARRAY(arr, ...) arr[##__VA_ARGS__##]
#define SET_MD_ARRAY(arr, value, ...) arr##[##__VA_ARGS__##] = value