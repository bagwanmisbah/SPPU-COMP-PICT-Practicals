class medicalsystem:
  def __init__(self):
    self.knowledge={
      "fever":["flu","cough","cold"],
      "cough":["flu","pneumonia"],
      "headache":["migraine","bp","flu"],
      "sore throat":["cough","cold"]
    }
    self.treat={
      "flu":"rest and fluids",
      "cold":"rest and anti-biotics",
      "cough":"warm water,cough syrup",
      "headache":"painkillers and dark room",
      "bp":"consult with doctor before any medications",
      "migraine":"painkillers and rest"
    }

  def diagnose(self):
      print("welcome to simple medical  expert system !")
      print("please answer yes or no to the following questions? ")

      symptoms=[]
      for s in self.knowledge:
        ans=input(f"do u have {s}?").lower()
        if ans=="yes":
          symptoms.append(s);

      conditions={}
      for s in symptoms:
        for c in self.knowledge[s]:
          conditions[c]=conditions.get(c,0)+1

      if not conditions:
        print("no conditions matched .see doctor if needed ")
      else:
        sorted_list=list(conditions.items())

        def get_count(t):
          return t[1]
        
        sorted_list.sort(key=get_count,reverse=True)
        top=sorted_list[0][0]

        print(self.treat[top])

if __name__=="__main__":
  m=medicalsystem()
  m.diagnose()