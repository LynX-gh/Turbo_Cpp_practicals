#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const unsigned int READ_BUFFER_SIZE = 1024 * 1024;
const unsigned int WRITE_BUFFER_SIZE = 2 * READ_BUFFER_SIZE;

unsigned char read_buffer[READ_BUFFER_SIZE];
unsigned char write_buffer[WRITE_BUFFER_SIZE];

int main(void)
{
    int program_status = EXIT_FAILURE;
    static const char hex_chars[] = "0123456789ABCDEF";
    do
    {
        ifstream srce_file("binary.dat", ios::binary);
        if (!srce_file)
        {
            cerr << "Error opening input file." << endl;
            break;
        }
        ofstream dest_file("binary.txt");
        if (!dest_file)
        {
            cerr << "Error creating output file." << endl;
        }

        // While no read errors from reading a block of source data:
        while (srce_file.read(&read_buffer[0], READ_BUFFER_SIZE))
        {
            // Get the number of bytes actually read.
            const unsigned int bytes_read = srce_file.gcount();

            // Define the index and byte variables outside
            //   of the loop to maybe save some execution time.
            unsigned int i = 0;
            unsigned char byte = 0;

            // For each byte that was read:
            for (i = 0; i < bytes_read; ++i)
            {
                // Get source, binary value.
                byte = read_buffer[i];

                // Convert the Most Significant nibble to an
                //   ASCII character using a lookup table.
                // Write the character into the output buffer.
                write_buffer[i * 2 + 0] = hex_chars[(byte >> 8)];

                // Convert the Least Significant nibble to an
                //   ASCII character and put into output buffer.  
                write_buffer[i * 2 + 1] = hex_chars[byte & 0x0f];
            }

            // Write the output buffer to the output, text, file.
            dest_file.write(&write_buffer[0], 2 * bytes_read);

            // Flush the contents of the stream buffer as a precaution.
            dest_file.flush();
        }
        dest_file.flush();
        dest_file.close();
        srce_file.close();
        program_status = EXIT_SUCCESS;
    } while (false);
    return program_status;
}