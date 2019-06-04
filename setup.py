# script for generating files 
import os.path

def main(folder):
    try: 
        task = os.path.join(folder, "1_task.md")
        file = open(task, "r+")

    except OSError as err:
        print("OS error: {0}".format(err))

    count = 0

    for line in file:
        line = line.strip()

        print (line)

        if (line.startswith("- [ ] https://")):
            questionName = line.split("/")[-1]

            print (questionName)

            if (questionName):
                questionName = questionName.replace("-", "_")

                fileName = questionName + ".cpp"

                filePath = os.path.join(folder, fileName)

                if os.path.isfile(filePath):
                    print("Error: File already created %s" % fileName)
                else:
                    print("Creating %s" % filePath)
                    count += 1
                    # newFile = open(filePath, "w+")

                    # newFile.close()

            else:   
                print("Empty URL. Please check URL path.")

    file.write("\n0/%i questions" % count)
    
    file.close()


if __name__=="__main__":
    main("week2/")

    