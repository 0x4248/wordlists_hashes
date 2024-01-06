/**
 * Hash - turns a wordlist into a csv containing the string, SHA256, and MD5
 * Github: https://www.github.com/lewisevans2007/hash
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char **argv) {
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    FILE *outfp = fopen("output.csv", "w");
    if (outfp == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    fprintf(outfp, "string,SHA256,MD5\n");
    char line[MAX_LINE_LEN];
    printf("Hashing file %s\n", filename);
    while (fgets(line, MAX_LINE_LEN, fp)) {
        char *newline_ptr = strchr(line, '\n');
        if (newline_ptr) {
            *newline_ptr = '\0';
        }
        unsigned char sha256[SHA256_DIGEST_LENGTH];
        SHA256(line, strlen(line), sha256);
        char sha256_str[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf(&sha256_str[i * 2], "%02x", sha256[i]);
        }
        sha256_str[2 * SHA256_DIGEST_LENGTH] = '\0';
        unsigned char md5[MD5_DIGEST_LENGTH];
        MD5(line, strlen(line), md5);
        char md5_str[2 * MD5_DIGEST_LENGTH + 1];
        for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
            sprintf(&md5_str[i * 2], "%02x", md5[i]);
        }
        md5_str[2 * MD5_DIGEST_LENGTH] = '\0';

        // Write line to output file
        fprintf(outfp, "%s,%s,%s\n", line, sha256_str, md5_str);
    }

    fclose(fp);
    fclose(outfp);
    return 0;
}
