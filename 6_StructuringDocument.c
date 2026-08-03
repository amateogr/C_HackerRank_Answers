#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Note the updated parameters: The backend passes 'Doc' as the first argument.

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

struct document get_document(char* text) {
    struct document doc;
    
    // 1. Count total paragraphs based on newlines
    int p_count = 1;
    for (int i = 0; text[i]; i++) {
        if (text[i] == '\n') p_count++;
    }
    doc.paragraph_count = p_count;
    doc.data = (struct paragraph*)malloc(p_count * sizeof(struct paragraph));
    
    char *p_start = text;
    for (int p = 0; p < p_count; p++) {
        // Find where the current paragraph ends
        char *p_end = strchr(p_start, '\n');
        if (!p_end) p_end = p_start + strlen(p_start);
        
        // 2. Count sentences in the current paragraph
        int s_count = 0;
        for (char *c = p_start; c < p_end; c++) {
            if (*c == '.') s_count++;
        }
        doc.data[p].sentence_count = s_count;
        doc.data[p].data = (struct sentence*)malloc(s_count * sizeof(struct sentence));
        
        char *s_start = p_start;
        for (int s = 0; s < s_count; s++) {
            // Find where the current sentence ends
            char *s_end = strchr(s_start, '.');
            
            // 3. Count words in the current sentence
            int w_count = 1;
            for (char *c = s_start; c < s_end; c++) {
                if (*c == ' ') w_count++;
            }
            if (s_end == s_start) w_count = 0; // Fallback for empty sentence
            
            doc.data[p].data[s].word_count = w_count;
            doc.data[p].data[s].data = (struct word*)malloc(w_count * sizeof(struct word));
            
            char *w_start = s_start;
            for (int w = 0; w < w_count; w++) {
                // Find where the current word ends
                char *w_end = strchr(w_start, ' ');
                if (!w_end || w_end > s_end) w_end = s_end;
                
                int len = w_end - w_start;
                doc.data[p].data[s].data[w].data = (char*)malloc(len + 1);
                strncpy(doc.data[p].data[s].data[w].data, w_start, len);
                doc.data[p].data[s].data[w].data[len] = '\0'; // Null-terminate the string
                
                w_start = w_end + 1; // Move past the space for the next word
            }
            s_start = s_end + 1; // Move past the period for the next sentence
        }
        p_start = p_end + 1; // Move past the newline for the next paragraph
    }
    
    return doc;
}