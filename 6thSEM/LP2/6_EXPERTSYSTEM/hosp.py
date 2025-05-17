class MedicalExpertSystem:
    def __init__(self):
        # Symptoms and related conditions
        self.knowledge = {
            "fever": ["flu", "cold", "malaria"],
            "cough": ["flu", "cold", "pneumonia"],
            "headache": ["flu", "migraine", "bp"],
            "sore throat": ["cold", "strep"],
            "fatigue": ["flu", "anemia", "thyroid"],
            "body aches": ["flu", "dengue"],
            "runny nose": ["cold", "allergy"],
            "short breath": ["pneumonia", "asthma"]
        }

        # Condition treatments
        self.treat = {
            "flu": "Rest and fluids",
            "cold": "Rest and OTC medicine",
            "malaria": "Antimalarial meds",
            "pneumonia": "Antibiotics",
            "migraine": "Painkillers and dark room",
            "bp": "See doctor for BP check",
            "strep": "Doctor's antibiotics",
            "anemia": "Iron and diet change",
            "thyroid": "Hormone pills",
            "dengue": "Fluids and doctor help",
            "allergy": "Avoid triggers, antihistamines",
            "asthma": "Inhaler and doctor care"
        }

    def diagnose(self):
        print("Welcome to Simple Medical Expert System")
        print("Answer yes/no for the following:")

        symptoms = []
        for s in self.knowledge:
            ans = input(f"Do you have {s}? ").lower()
            if ans == "yes":
                symptoms.append(s)

        # Find possible conditions
        conditions = {}
        for s in symptoms:
            for c in self.knowledge[s]:
                conditions[c] = conditions.get(c, 0) + 1

        if not conditions:
            print("\nNo condition matched. See a doctor if needed.")
        else:
            sorted_list = sorted(conditions.items(), key=lambda x: x[1], reverse=True)
            print("\nPossible conditions:")
            for i, (c, count) in enumerate(sorted_list, 1):
                print(f"{i}. {c} (matched: {count})")

            top = sorted_list[0][0]
            print(f"\nSuggested treatment for {top}: {self.treat[top]}")
            print("Note: This is not a real medical diagnosis.")

# Run
if __name__ == "__main__":
    m = MedicalExpertSystem()
    m.diagnose()
