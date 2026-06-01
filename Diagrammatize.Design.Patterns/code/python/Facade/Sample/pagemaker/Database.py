import json

class Database:
    @staticmethod
    def getProperties(dbname):
        filename = dbname + ".json"
        prop = None
        try:
            prop = json.load(open(filename))
        except Exception as e:
            print("Warning: " + filename + " is not found.")
        return prop



