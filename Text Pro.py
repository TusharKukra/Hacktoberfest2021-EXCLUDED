def sentence_maker(phrase):
    introgetory = ("How", "When", "Why", "Who", "Where")
    capitalize = phrase.capitalize()
    if capitalize.startswith(introgetory):
        return "{}?".format(capitalize)
    else:
        return "{}.".format(capitalize)

result = []

while True:
    user_input = input("Say something: ")
    if user_input == "end":
        break
    else:
        result.append(sentence_maker(user_input))

print(" ".join(result))
