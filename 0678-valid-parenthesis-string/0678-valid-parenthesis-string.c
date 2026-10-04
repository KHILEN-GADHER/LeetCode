bool checkValidString(char* s) {
    int min_open = 0;
    int max_open = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            min_open++;
            max_open++;
        } else if (s[i] == ')') {
            min_open--;
            max_open--;
        } else { 
            min_open--;
            max_open++;
        }
        if (max_open < 0) {
            return false;
        }
     if (min_open < 0) {
            min_open = 0;
        }
    }
    
    // Valid if it's possible to have exactly 0 open left parentheses
    return min_open == 0;

}
