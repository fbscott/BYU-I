from collections import deque

class Song:
    def __init__(self):
        '''song constructor'''
        self.title = ''
        self.artist = ''

    def prompt(self):
        '''prompt for song data'''
        self.title = input('\nEnter the title: ')
        self.artist = input('Enter the artist: ')
        print()

    def display(self):
        '''display song data'''
        print('\nPlaying song:')
        print(f'{self.title} by {self.artist}\n')

def createNewSong():
    '''create a new song object and get data from user'''
    song = Song()
    song.prompt()
    return song

def main():
    '''initialize the program'''
    playlist = deque()

    # current selection
    option = 0

    # keep prompting the user until the quit command (4) is entered
    while option != 4:
        print("Options: ")
        print("1. Add a new song to the end of the playlist")
        print("2. Insert a new song to the beginning of the playlist")
        print("3. Play the next song")
        print("4. Quit")

        # select option
        option = int(input("Enter selection: "))

        # add song to end of list
        if option == 1:
            playlist.append(createNewSong())

        # add song to beginning of list
        elif option == 2:
            playlist.appendleft(createNewSong())

        # play first song in list if there is one
        elif option == 3:
            if len(playlist) == 0:
                print('\nThe playlist is currently empty.\n')
            else:
                playlist[0].display()
                playlist.popleft()

    print('\nGoodbye')

if __name__ == '__main__':
    main()
