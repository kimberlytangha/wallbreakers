# script for generating files 
import os.path

def main(folder):
    try: 

        task = os.path.join(folder, "task.md")
        
        file = open(task, "r")

        for line in file:
            line = line.strip()

            if (line.startswith("https://")):
                questionName = line.split("/")[-1]

                if (questionName):
                    questionName = questionName.replace("-", "_")

                    fileName = questionName + ".cpp"

                    filePath = os.path.join(folder, fileName)

                    if os.path.isfile(filePath):
                        print("Error: File already created %s" % fileName)
                    else:
                        print("Creating %s" % filePath)
                        newFile = open(filePath, "w+")

                        newFile.close()

                else:   
                    print("Empty URL. Please check URL path.")

    except OSError as err:
        print("OS error: {0}".format(err))

if __name__=="__main__":
    main("week2/")

    