#include <time.h>
#define DATABLOCK_NUM 5
#define FILENAME_SIZE 200

typedef struct{
	unsigned int datablocks[DATABLOCK_NUM];
} Datastream;

typedef struct{
	unsigned int nodeid;
	unsigned int offset;
	char *filename;
	unsigned int size;
	unsigned int type; //1-file 2-folder 3-link
	unsigned int parent_nodeid;
	time_t creation_time;
	time_t access_time;
	time_t modification_time;
	Datastream data;
} MDS;

typedef struct{
	unsigned int datablocks_size;
	unsigned int metadata_size;
	unsigned int root_mds_offset;
	unsigned int latest_nodeid;
} Superblock;

typedef struct{
	char *array;
} Bitmap;

typedef struct list_node{
	unsigned int nodeid;
	unsigned int offset;
	struct list_node *parent_dir;
}list_node;
