#ifndef GAPBUFFER_HPP
#define GAPBUFFER_HPP

#include <cstdint>
#include <stdio.h>

namespace PRO
{
    class GapBuffer
    {
	private:

	    char* cursor;		// location of the cursor in the buffer
	    char* buffer; 		// start of the buffer
	    char* bufferEnd;		// first location past the buffer

	    char* gapStart;		// start of gap
	    char* gapEnd;		// first location past the gap
	
	    uint8_t gapSize;		// max gap size in a given context
	
	public:
	    
	    // Constructor with gap size of the buffer
	    GapBuffer(const int gapSize);

	    // Constructor with a file
	    GapBuffer(FILE* file, const int gapSize);
    
	    // Destructor
	    ~GapBuffer();
	
	    /*
	     *	Returns the size of the buffer minus the gap
	     */ 
	    int BufferSize() const;
	    
	    /*
	     *	Move the gap to cursor
	     */
	    void MoveGapToCursor();
	    
	    /*
	     * Set cursor to offset from start of the buffer
	     */
	    void SetCursor(const unsigned int offset);
	    
	    /*
	     * Returns the current size of the gap
	     */
	    int SizeOfGap();
	    
	    /*
	     * Returns the offset of the cursor from the start of the buffer
	     */
	    unsigned int CursorOffset();
	    
	    /*
	     * Return the character that cursor is pointing to.
	     * If cursor is inside the gap, then return the first character
	     * outside the gap
	     */
	    char GetChar();
	
	    /*
	     * Return the previous character and move cursor back one position
	     */
	    char PreviousChar();
	    
	    /*
	     * Return the next character and move cursor forward one position
	     */
	    char NextChar();

	    /*
	     * Replace the character and move the cursor
	     */
	    void ReplaceChar(const char ch);
	    
	    /*
	     * Inserts a character at cursor position,
	     * advance cursor
	     */
	    void PutChar(const char ch);

	    /*
	     *	Insert Character at cursor position,
	     *	but doesn't advance forward
	     */
	    void InsertChar(const char ch);
	    
	    /*
	     * Inserts a length sized string at the cursor
	     */
	    void InsertString(const char* string, const unsigned int length);

	    /*
	     * Deletes size no of characters
	     */
	    void DeleteChars(const unsigned int size);
	    
	    /*
	     * Prints out the current buffer from start
	     */
	    void PrintBuffer();

	    /*
	     * Saves to File the no of bytes starting from the cursor
	     */
	    bool SaveToFile(FILE* file, const unsigned int bytes);
    };
}
#endif
