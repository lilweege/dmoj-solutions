

int strStr(char * haystack, char * needle){
    char* p = strstr(haystack, needle);
    return p == 0 ? -1 : (p - haystack);
}