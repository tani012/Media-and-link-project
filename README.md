# WhatsApp Group Chat Media and Link Counter

## Objective

The objective of this program is to analyze a WhatsApp group chat text file and count the occurrences of media and links shared by each user in the chat.

## Methodology

The C program reads the contents of the WhatsApp group chat text file line by line. It extracts usernames, counts the occurrences of "<Media omitted>", and identifies URLs using regular expressions. After processing the file, the program provides the counts of media and links shared by each user in the chat.


## How to Use

1. Compile the program using a C compiler (e.g., GCC):
   ```bash
   gcc whatsapp_media_link_counter.c -o whatsapp_media_link_counter
2. Run the compiled program:
   ./whatsapp_media_link_counter
3. Enter the filename of the WhatsApp group chat text file when prompted.
4. Choose an option:
   - Enter the index of a specific user to get their media and link counts.
   - Enter 1025 to get the counts of media and links shared by all users separately.
   - Enter 1026 to get the total counts of media and links in the chat.
   - Enter -1 to exit the program.
  
## Example

Suppose you have a WhatsApp group chat text file named chat.txt. After running the program and entering chat.txt as the filename, you can choose to view counts for specific users, counts for all users separately, or the total counts of media and links in the chat.

## Requirements
  - C compiler (e.g., GCC)
  - Input WhatsApp group chat text file (*.txt format)


