import nltk
from nltk.chat.util import Chat, reflections


#defining rules
pairs=[
    [
        r"My name is (.*)",
        ["Hello %1, how are you today?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello","Hi there",]
    ],
    [
        r"What is your name?",
        ["I am a chatbot 777",]
    ],
    [
        r"How are you?",
        ["I am doing good and what about you?",]
    ],
    [
        r"Sorry (.*)",
        ["It's ok, no problem!","Forget about it!",]
    ],
    [
        r"I am fine",
        ["Greate to hear that ! How can I help you?",]
    ],
    [
        r"i'm (.*) doing good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program dude and Seriously you are asking me this?",]
    ],
    [
        r"what (.*) want ?",
        ["Make me an offer I can't refuse",]
    ],
    [
        r"(.*) created ?",
        ["Ajay created me using Python's NLTK library ","top secret ;)",]
    ],
    [
        r"(.*) (location|city) ?",
        ['Pune, Maharashtra',]
    ],
    [
        r"how is weather in (.*)?",
        ["Weather in %1 is awesome like always","Too hot man here in %1","Too cold man here in %1","Never even heard about %1"]
    ],
    [
        r"i work in (.*)?",
        ["%1 is an Amazing company, I have heard about it. But they are in huge loss these days.",]
    ],
    [
        r"(.*)raining in (.*)",
        ["No rain since last week here in %2","Damn its raining too much here in %2"]
    ],
    [
        r"how (.*) health(.*)",
        ["I'm a computer program, so I'm always healthy ",]
    ],
    [
      r"Do your company have stores in Pune (.*)",
      ["Yes, we have our stores in Katraj,Shivaji Nagar, Swargate and many more places! To find out locations go to our website www.grocerycare.com"]  
    ],
    [
        r"How can I order from your website(.*)",
        ["Add items to your bag and from there you can easily place your order! For more information see video present on the home screen. It will really help you!"]  
    ],
    [
        r"How much discount will be there on big billon days (.*)",
        ["Sorry sir, we cannot tell you exactly but discount varies from item to item"]
    ],
    [
        r"quit",
        ["BBye take care. See you soon :) ","It was nice talking to you. See you soon :)"]
    ]
]

def chat():
    print("Hello I am a chatbot created by Sourabh! How can I help you?")
    chat = Chat(pairs,reflections)
    chat.converse()
    
if __name__ == "__main__":
    chat()
    
