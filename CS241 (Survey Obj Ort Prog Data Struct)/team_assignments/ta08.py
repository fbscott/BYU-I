class Time:
    def __init__(self, hours = 0, minutes = 0, seconds = 0):
        self._hours = int(hours)
        self._minutes = int(minutes)
        self._seconds = int(seconds)

    def _get_hours(self):
        return self._hours

    def _set_hours(self, hours):
        if hours < 0:
            self._hours = 0
        elif hours > 23:
            self._hours = 23
        else:
            self._hours = hours

    def _get_minutes(self):
        return self._minutes

    def _set_minutes(self, minutes):
        if minutes < 0:
            self._minutes = 0
        elif minutes > 59:
            self._minutes = 59
        else:
            self._minutes = minutes

    def _get_seconds(self):
        return self._seconds

    def _set_seconds(self, seconds):
        if seconds < 0:
            self._seconds = 0
        elif seconds > 59:
            self._seconds = 59
        else:
            self._seconds = seconds

    hours = property(_get_hours, _set_hours)
    minutes = property(_get_minutes, _set_minutes)
    seconds = property(_get_seconds, _set_seconds)

def main():
    time = Time()

    time.hours = int(input('Hours: '))
    time.minutes = int(input('Minutes: '))
    time.seconds = int(input('Seconds: '))

    print()

    print(f'{time.hours} : {time.minutes} : {time.seconds}')

if __name__ == "__main__":
    main()
