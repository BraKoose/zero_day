#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    FILE *frame;
    int frameNum = 1;

    while (1) {
        char filename[30]; // Increase buffer size to 30 to accommodate the generated filename
        snprintf(filename, sizeof(filename), "simpsons_frame_%d.txt", frameNum);

        frame = fopen(filename, "r");
        if (!frame) {
            break;
        }

        char line[256];
        while (fgets(line, sizeof(line), frame)) {
            printf("%s", line);
        }

        fclose(frame);
        usleep(100000);  // Adjust the usleep time to control animation speed
        frameNum++;
    }

    return 0;
}

