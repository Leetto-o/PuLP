#include <stdio.h>
#include <stdint.h>
#include <iostream>

int main(int argc, char **argv) {
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "wb");
    uint32_t edge[2];
    uint32_t label;
    uint32_t max = 0;
    size_t count = 0;
    while (fscanf(fin, "%u\t%u\t%u\n", &edge[0], &edge[1], &label) != EOF)
    {
        count++;
        if (count % 500000 == 0) {
        // printf("%llu\n", count);
            std::cout << count << "\t" << edge[0] << "\t" << edge[1] << std::endl;
        }
        if (edge[0] > max) {
            max = edge[0];
        }
        if (edge[1] > max) {
            max = edge[1];
        }
        fwrite(edge, sizeof(uint32_t), 2, fout);
    }
    // printf("total edges: %llu max_vertex: %u", count, max);
    std::cout << "total edges: " << count << " max_vertex: " << max << std::endl;
    return 0;
}
