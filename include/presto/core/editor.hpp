#ifndef EDITOR_HPP
#define EDITOR_HPP

enum State
{
    READONLY,
    READWRITE,
    MODIFIED,
};

typedef struct EditorContext
{
    // State of the current context
    State state;

} EditorContext;

#endif 
