const char* concatenate(const char* str1, const char* str2) {
    int str1Len = 0;
    int str2Len = 0;
    while (str1[str1Len] != '\0') {
        str1Len++;
    }
    while (str2[str2Len] != '\0') {
        str2Len++;
    }
    char* result = new char[str1Len + str2Len + 1];
    for (int i = 0; i < str1Len; i++) {
        result[i] = str1[i];
    }
    for (int i = 0; i < str2Len; i++) {
        result[str1Len + i] = str2[i];
    }
    return result;
}