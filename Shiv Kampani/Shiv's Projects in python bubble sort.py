
print("How many values do you have?")


def sortList(reverse=True):
    unorderedlist=[1,300,50,20,8,60]
    listlength=len(unorderedlist)

    for i in range(0,listlength):
        print(unorderedlist) 
        for i in range(0,listlength-1):
            if(reverse):       
                if(unorderedlist[i]>unorderedlist[i+1]):
                    a=unorderedlist[i+1]
                    unorderedlist[i+1]=unorderedlist[i]
                    unorderedlist[i]=a

            if(not reverse):       
        
                if(unorderedlist[i]<unorderedlist[i+1]):
                    a=unorderedlist[i+1]
                    unorderedlist[i+1]=unorderedlist[i]
                    unorderedlist[i]=a

        
                




       
sortList(False)
