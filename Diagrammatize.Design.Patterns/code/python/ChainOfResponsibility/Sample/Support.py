import abc

class Support(abc.ABC):
    def __init__(self, name):
        self.name = name
        self.next = None

    def setNext(self, next_):
        self.next = next_
        return next_

    def support(self, trouble):
        if self.resolve(trouble):
            self.done(trouble)
        elif self.next is not None:
            self.next.support(trouble)
        else:
            self.fail(trouble)

    def __str__(self):
        return "[{}]".format(self.name)

    @abc.abstractmethod
    def resolve(self, trouble):
        pass

    def done(self, trouble):
        print("{} is resolved by {}.".format(trouble, self))

    def fail(self, trouble):
        print("{} cannot be resolved.".format(trouble))
