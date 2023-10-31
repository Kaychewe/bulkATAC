#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Data structure to hold parsed arguments
typedef struct {
    char *file1;    // BAM file 1
    char *file2;    // BAM file 2
    char *motif;    // Motif file
    bool help_flag; // Help flag
} arguments;

// Function to initialize arguments structure
void initialize_arguments(arguments *args) {
    args->file1 = NULL;
    args->file2 = NULL;
    args->motif = NULL;
    args->help_flag = false;
}

// Function to print usage/help message
void print_usage() {
    printf("Usage: diffATAC -b <file1.bam> -B <file2.bam> -m <motif.jaspar>\n");
    printf("Options:\n");
    printf("  -b   BAM file 1\n");
    printf("  -B   BAM file 2\n");
    printf("  -m   Motif file\n");
    printf("  -h   Print this help message\n");
}

// Function to parse command-line arguments
void parse_arguments(int argc, char **argv, arguments *args) {
    int i = 1; // start from the first argument after program name
    while (i < argc) {
        if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            args->file1 = argv[i + 1];
            i += 2;
        } else if (strcmp(argv[i], "-B") == 0 && i + 1 < argc) {
            args->file2 = argv[i + 1];
            i += 2;
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            args->motif = argv[i + 1];
            i += 2;
        } else if (strcmp(argv[i], "-h") == 0) {
            args->help_flag = true;
            i++;
        } else {
            printf("Error: Unrecognized option %s\n", argv[i]);
            print_usage();
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    arguments args;
    initialize_arguments(&args);
    parse_arguments(argc, argv, &args);
    
    if (args.help_flag || argc == 1) {
        print_usage();
        exit(0);
    }
    
    // Print parsed arguments for demonstration
    printf("BAM file 1: %s\n", args.file1);
    printf("BAM file 2: %s\n", args.file2);
    printf("Motif file: %s\n", args.motif);

    // Rest of the program logic...

    return 0;
}
