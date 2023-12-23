#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>

size_t randomWord(char *buffer, size_t size, size_t nmemb, char *userp){
	int bufferLength = size * nmemb;
	int wordLength = bufferLength - 4;
	userp = realloc(userp, sizeof(char) * wordLength);
	int counterJ = 0;
	for(int i = 0; i < bufferLength; i++){
		if(buffer[i] == '[' || buffer[i] == ']' || buffer[i] == '"' || userp[counterJ] == buffer[i]){
			continue;
		}
		userp[counterJ] = buffer[i];
		counterJ++;
	}
	userp[counterJ] = 0x00;
	printf("Buffer is: %s\n", buffer);
	printf("Length is: %d\n", bufferLength);
	printf("Counter is: %d\n", counterJ);
	return bufferLength;
}

char *word(){
	CURL *handle;
	CURLcode result;
	char *word = malloc(sizeof(char));

	handle = curl_easy_init();
	if(!handle){
		return NULL;
	}
	curl_easy_setopt(handle, CURLOPT_URL, "https://random-word-api.herokuapp.com/word");
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, randomWord);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, word);
	result = curl_easy_perform(handle);
	if(result != CURLE_OK){
		fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
	}
	printf("Random word is: %s\n", word);
	curl_easy_cleanup(handle);
	return word;
}
