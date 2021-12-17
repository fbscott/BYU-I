
# Open the file

# Read through it character by character
# One way to do this for this program, is to read line by line
# and then call line.strip() to get rid of any whitespace
for (line in ...)
    # If current character is any type of opening brace: (, {, [
        # push it (the current character) on to a stack

    # if current character is any type of closing brace: ), }, ]
        # compare it to the thing on the top of the stack
            # If the stack is empty (nothing to compare)
                # Quit now, it doesn't match
            # if they match (meaning closing of the same type):
                # We're good
                # Pop the opening brace off the stack
            # If they don't match
                # Quit now, and tell them the braces don't match
    
# after reading the complete file

# If there is anything on the stack, the braces didn't match
