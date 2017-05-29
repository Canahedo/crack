/*

    Filename: crack
    Author: Canahedo
    
    This program brute forces a password of up to 4 chars using salt "50"
    
*/    

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int compare (string attempt, string given);

int main (int argc, string argv[]){
    
    // Variable declaration
    bool match = false;
    char pw[5];
    int pwLen = 1;
    string attempt = "";
    string salt = "50";

    // Ensures exactly one hash has been entered
    if (argc != 2){
        printf("Valid key required\n");
        return 1;
    }
    
    
    // Creates strings and runs them thru 'compare' function
    // Controls first letter
    while (match == false && pwLen < 5){
        
        pw[1] = '\0';
        
        for (int i = 0; i < 58; i++){
            
            // Skips trash chars
            if (i == 26){
                i = 32;
            }
            
            // Sets first letter        
            pw[0] = 'A' + i;
            
            // Compare if looking for one char password
            if (pwLen == 1){
                attempt = crypt(pw, salt);
                if (compare ( attempt , argv[1])){
                    match = true;
                }
            }
            
                            // Controls second char
                            // Runs exactly as above
                            if (pwLen > 1 && match == false){
                                
                                pw[2] = '\0';
                                
                                for (int j = 0; j < 58; j++){
                                    
                                    if (j == 26){
                                        j = 32;
                                    }
                                        
                                    pw[1] = 'A' + j;
                                    
                                    // Compare if looking for two char password
                                    if (pwLen == 2){
                                        attempt = crypt(pw, salt);
                                        if (compare ( attempt , argv[1])){
                                            match = true;
                                        }
                                    }
                                    
                                                    // Controls third char
                                                    // Runs exactly as above 
                                                    if (pwLen > 2 && match == false){
                                                        
                                                        pw[3] = '\0';
                                                        
                                                        for (int k = 0; k < 58; k++){
                                                            
                                                            if (k == 26){
                                                                k = 32;
                                                            }
                                                            
                                                            pw[2] = 'A' + k;
                                                            
                                                            // Compare if looking for three char password
                                                            if (pwLen == 3){
                                                                attempt = crypt(pw, salt);
                                                                if (compare ( attempt , argv[1])){
                                                                    match = true;
                                                                }
                                                            }
                                                                            // Controls fourth char
                                                                            // Runs exactly as above
                                                                            if (pwLen > 3 && match == false){
                                                                                
                                                                                pw[4] = '\0';
                                                                                
                                                                                for (int l = 0; l < 58; l++){
                                                                                
                                                                                    if (l == 26){
                                                                                        l = 32;
                                                                                    }
                                                                                    
                                                                                    pw[3] = 'A' + l;
                                                                                    
                                                                                    // Compare if looking for four char password
                                                                                    if (pwLen == 4){
                                                                                        attempt = crypt(pw, salt);
                                                                                        if (compare ( attempt , argv[1])){
                                                                                            match = true;
                                                                                        }
                                                                                    }
                                                                                    
                        // Kills all loops once match == true
                                                                                    if (match == true){
                                                                                        break;
                                                                                    }
                                                                                }    
                                                                            }
                                                            if (match == true){
                                                                break;
                                                            }
                                                        }
                                                    }
                                    if (match == true){
                                        break;
                                    }
                                }
                            }
            if (match == true){
                break;
            }
        }
        
        // Increments pwLen, so if another loop is triggered, one more char will be attempted
        pwLen++;
        
    }
    
    
    if (match == true){
        // Print ptext password
        printf("%s\n", pw);
        return 0;
        
    } else {
        // Print error msg
        printf("Error: Password not found\n");
        return 1;
    }
    
}    
    

//This function compares two hash strings char by char

int compare (string attempt, string given){
    bool match = false;
    for (int i = 0, n = strlen(given); i < n; i++){
        if (attempt[i] == given [i]){
            match = true;
        }else{
            match = false;
            break;
        }
    }
    return match;
}