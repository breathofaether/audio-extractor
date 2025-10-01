#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char input[100];
    char output[100];
    int choice;
    char command[300];
    char buffer[256];

    printf("Enter input video filename: ");
    scanf("%99s", input);

    // Show metadata using ffprobe
    printf("\nFetching metadata...\n\n");
    sprintf(command,
            "ffprobe -v error -show_entries stream=codec_name,channels "
            "-of default=noprint_wrappers=1 \"%s\"",
            input);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: failed to run ffprobe.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);  
    }
    pclose(fp);

    printf("\nEnter output audio filename (e.g., output.mp3): ");
    scanf("%99s", output);

    printf("\nChoose audio channel option:\n");
    printf("1. Keep original\n");
    printf("2. Convert to mono (1 channel)\n");
    printf("3. Convert to stereo (2 channels)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 2) {
        sprintf(command, "ffmpeg -i \"%s\" -q:a 0 -ac 1 -map a \"%s\"", input, output);
    } else if (choice == 3) {
        sprintf(command, "ffmpeg -i \"%s\" -q:a 0 -ac 2 -map a \"%s\"", input, output);
    } else {
        sprintf(command, "ffmpeg -i \"%s\" -q:a 0 -map a \"%s\"", input, output);
    }

    printf("\nRunning command:\n%s\n\n", command);

    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error: failed to run ffmpeg.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer); 
    }

    pclose(fp);
    printf("\nDone! Audio saved as %s\n", output);

    return 0;
}
