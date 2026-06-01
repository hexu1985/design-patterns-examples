
class FileTreatmentException(Exception):
    def __init__(self, msg=None):
        super().__init__(msg)
        self.msg = msg

    def __str__(self):
        return "FileTreatmentException({})".format(self.msg)
