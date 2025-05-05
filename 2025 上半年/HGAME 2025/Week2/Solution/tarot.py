Major_Arcana = [
    "The Fool",
    "The Magician",
    "The High Priestess",
    "The Empress",
    "The Emperor",
    "The Hierophant",
    "The Lovers",
    "The Chariot",
    "Strength",
    "The Hermit",
    "Wheel of Fortune",
    "Justice",
    "The Hanged Man",
    "Death",
    "Temperance",
    "The Devil",
    "The Tower",
    "The Star",
    "The Moon",
    "The Sun",
    "Judgement",
    "The World",
]
wands = [
    "Ace of Wands",
    "Two of Wands",
    "Three of Wands",
    "Four of Wands",
    "Five of Wands",
    "Six of Wands",
    "Seven of Wands",
    "Eight of Wands",
    "Nine of Wands",
    "Ten of Wands",
    "Page of Wands",
    "Knight of Wands",
    "Queen of Wands",
    "King of Wands",
]
cups = [
    "Ace of Cups",
    "Two of Cups",
    "Three of Cups",
    "Four of Cups",
    "Five of Cups",
    "Six of Cups",
    "Seven of Cups",
    "Eight of Cups",
    "Nine of Cups",
    "Ten of Cups",
    "Page of Cups",
    "Knight of Cups",
    "Queen of Cups",
    "King of Cups",
]
swords = [
    "Ace of Swords",
    "Two of Swords",
    "Three of Swords",
    "Four of Swords",
    "Five of Swords",
    "Six of Swords",
    "Seven of Swords",
    "Eight of Swords",
    "Nine of Swords",
    "Ten of Swords",
    "Page of Swords",
    "Knight of Swords",
    "Queen of Swords",
    "King of Swords",
]
pentacles = [
    "Ace of Pentacles",
    "Two of Pentacles",
    "Three of Pentacles",
    "Four of Pentacles",
    "Five of Pentacles",
    "Six of Pentacles",
    "Seven of Pentacles",
    "Eight of Pentacles",
    "Nine of Pentacles",
    "Ten of Pentacles",
    "Page of Pentacles",
    "Knight of Pentacles",
    "Queen of Pentacles",
    "King of Pentacles",
]
Minor_Arcana = wands + cups + swords + pentacles
tarot = Major_Arcana + Minor_Arcana


def Reverse_wheel(FATE):
    FATEd = [
        (FATE[0] - FATE[1] + FATE[2] - FATE[3] + FATE[4]) // 2,
        (FATE[0] + FATE[1] - FATE[2] + FATE[3] - FATE[4]) // 2,
        (-FATE[0] + FATE[1] + FATE[2] - FATE[3] + FATE[4]) // 2,
        (FATE[0] - FATE[1] + FATE[2] + FATE[3] - FATE[4]) // 2,
        (-FATE[0] + FATE[1] - FATE[2] + FATE[3] + FATE[4]) // 2,
    ]
    return FATEd


final_Value = [
    2532951952066291774890498369114195917240794704918210520571067085311474675019,
    2532951952066291774890327666074100357898023013105443178881294700381509795270,
    2532951952066291774890554459287276604903130315859258544173068376967072335730,
    2532951952066291774890865328241532885391510162611534514014409174284299139015,
    2532951952066291774890830662608134156017946376309989934175833913921142609334,
]

Value = final_Value
for i in range(250):
    Value = Reverse_wheel(Value)

initial_FATE = []
for i in Value:
    if i < 0:
        initial_FATE.append("re-" + tarot[(i ^ -1) % 78])
    else:
        initial_FATE.append(tarot[i % 78])

FLAG = ("hgame{" + "&".join(initial_FATE) + "}").replace(" ", "_")
print(FLAG)
# hgame{re-The_Moon&re-The_Sun&Judgement&re-Temperance&Six_of_Cups}
