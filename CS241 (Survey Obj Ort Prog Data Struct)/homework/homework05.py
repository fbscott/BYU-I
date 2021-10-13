stack = []
opening_brackets = ['{', '[', '(']
# for comparison
# saves a lot of if/else logic by just accessing a closing bracket for a given
# opening bracket
brackets_dict = {
    '{':'}',
    '[':']',
    '(':')'
}

def get_file():
    """file from testBed"""
    # return "c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\stacks05\\stacks06.txt"
    return input("File: ")

def is_balanced(file_name):
    """build the stack and return a boolean value if it is balanced or not"""
    # read the file
    with open(file_name) as file:
        # Parse the file. No need to go overboard. Each line only contains one
        # character.
        for line in file:
            # character is an opening bracket
            if(line.strip() in opening_brackets):
                stack.append(line.strip())
            # character is a closing bracket and there's data in the stack
            elif(stack): # stack != []
                # remove the topmost element from the stack (stack[-1]) and
                # save it for comparison
                top = stack.pop()
                # compare the popped element to the corresponding bracket from
                # the dictionary
                if(brackets_dict[top] != line.strip()): # mismatch
                    return False
            # if we've gotten to this point, the current character is a closing
            # bracket, but the stack is empty
            else:
                return False

        # if there's still data in the stack at this point, then there's a
        # missing closing bracket
        if(stack):
            return False
        # everything is balanced
        # default condition
        else:
            return True

    file.close()

def main():
    """do all the things"""
    user_provided_file = get_file()

    print("Balanced") if is_balanced(user_provided_file) else print("Not balanced")

if __name__ == '__main__':
    main()
