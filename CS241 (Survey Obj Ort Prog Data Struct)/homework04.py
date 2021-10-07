from collections import deque

class Song:
    def __init__(self):
        self.title = ''
        self.artist = ''

    def prompt(self):
        self.title = input('\nEnter the title: ')
        self.artist = input('Enter the artist: ')
        print()

    def display(self):
        print('\nPlaying song:')
        print(f'{self.title} by {self.artist}\n')

def main():
    playlist = deque()

    option = 0

    while option != 4:
        print("Options: ")
        print("1. Add a new song to the end of the playlist")
        print("2. Insert a new song to the beginning of the playlist")
        print("3. Play the next song")
        print("4. Quit")
        option = int(input("Enter selection: "))

        if option == 1:
            song = Song()
            song.prompt()
            playlist.append(song)

        elif option == 2:
            song = Song()
            song.prompt()
            playlist.appendleft(song)

        elif option == 3:
            if len(playlist) == 0:
                print('\nThe playlist is currently empty.\n')
            else:
                playlist[0].display()
                playlist.popleft()

    print('\nGoodbye')


if __name__ == '__main__':
    main()
