def testValid():
    """
    Test for valid SQL queries

    """
    pass

def testTautology():
    """
    Test for tautology attacks

    """
    pass

def testUnion():
    """
    Test for union attacks

    """
    pass

def testAddState():
    """
    Test for additional statement attacks

    """
    pass

def testComment():
    """
    Test for comment attacks

    """
    pass

def genQuery(username, password):
    """
    Query Generation
    Accept two strings (username and a password) and returns a single string
    (SQL) representing the query used to determine if a user is authenticated
    on a given system.
    """
    return f"SELECT authenticate FROM passwordList WHERE username='${username}' and passwd='${password}';"

def genQueryWeak(username, password):
    """
    Query Generation - Erik
    """
    pass

def genQueryStrong(username, password):
    """
    Query Generation - Scott
    """
    pass

def main():
    print(genQuery('some username', 'some password'))

if __name__ == "__main__":
    main()
