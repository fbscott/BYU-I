stack = []
opening_brackets = ['{', '[', '(']
brackets_dict = {
    '{':'}',
    '[':']',
    '(':')'
}

def prompt():
    # return "c:\\git_repos\\BYU-I\\CS241 (Survey Obj Ort Prog Data Struct)\\_data\\stacks05\\stacks06.txt"
    return input("File: ")

def read_file(file_name):
    """read the file"""
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
                if(brackets_dict[top] != line.strip()):
                    print("Not balanced")
                    return
            # if we've gotten to this point, the current character is a closing
            # bracket, but the stack is empty
            else:
                print("Not balanced")
                return

        # if there's still data in the stack at this point, then there's a
        # missing closing bracket
        if(stack):
            print("Not balanced")
        # everything is balanced
        else:
            print("Balanced")

    file.close()

def main():
    """do all the things"""
    user_provided_file = prompt()

    read_file(user_provided_file)

if __name__ == '__main__':
    main()
