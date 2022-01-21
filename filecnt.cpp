#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>
#include <cstring>

using std::cout;

int dirCount(char * name) {
    int cnt = 0;
    DIR * dir = opendir(name);
    if(dir == nullptr) {
        cout << "Error opening dir " << name << ".\n";
    }
    else {
        struct dirent * dirData;
        dirData = readdir(dir);

        while(dirData != nullptr) {
            char filepath[1000] = {0};
            strcat(filepath, name);
            strcat(filepath, "/");
            strcat(filepath, dirData->d_name);
            if(dirData->d_type == DT_DIR && strcmp(dirData->d_name, ".") != 0 && strcmp(dirData->d_name, "..") != 0) {
                cnt += dirCount(filepath) + 1;
            }
            dirData = readdir(dir);
        }
        closedir(dir);
    }
    return cnt;
}

int fileCount(char * name) {
    int cnt = 0;
    DIR * dir = opendir(name);
    if(dir == nullptr) {
        cout << "Error opening dir " << name << ".\n";
    }
    else {
        struct dirent * dirData;
        dirData = readdir(dir);

        while(dirData != nullptr) {
            char filepath[1000] = {0};
            strcat(filepath, name);
            strcat(filepath, "/");
            strcat(filepath, dirData->d_name);
            if(dirData->d_type == DT_DIR && strcmp(dirData->d_name, ".") != 0 && strcmp(dirData->d_name, "..") != 0) {
                cnt += fileCount(filepath);
            }
            else {
                cnt++;
            }
            dirData = readdir(dir);
        }
        closedir(dir);
    }
    return cnt;
}

long long int byteCount(char * name) {
    long long int cnt = 0;
    DIR * dir = opendir(name);
    if(dir == nullptr) {
        cout << "Error opening dir " << name << ".\n";
    }
    else {
        struct dirent * dirData;
        dirData = readdir(dir);

        while(dirData != nullptr) {
            char filepath[1000] = {0};
            strcat(filepath, name);
            strcat(filepath, "/");
            strcat(filepath, dirData->d_name);
            if(dirData->d_type == DT_DIR && strcmp(dirData->d_name, ".") != 0 && strcmp(dirData->d_name, "..") != 0) {
                cnt += byteCount(filepath);
            }
            else {
                struct stat statData;
                stat(filepath, &statData);
                cnt += statData.st_size;
            }
            dirData = readdir(dir);
        }
        closedir(dir);
    }
    return cnt;
}

int main(int argc, char * argv[]) {

    for(int i = 1; i < argc; i++) {
        int dirCnt = dirCount(argv[i]);
        cout << "The total number of directories in directory " << argv[i] << " is: " << dirCnt << "\n";
        int fileCnt = fileCount(argv[i]);
        cout << "The total number of files in directory " << argv[i] << " is: " << fileCnt << "\n";
        long long int byteCnt = byteCount(argv[i]);
        cout << "The total number of bytes occupied by all files in directory " << argv[i] << " is: " << byteCnt << "\n";
    }

    return 0;
}
