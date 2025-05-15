
import nltk
from nltk.chat.util import Chat, reflections
from datetime import datetime


def get_greeting():
    current_hour = datetime.now().hour
    if current_hour < 12:
        return "Good morning!"
    elif current_hour < 18:
        return "Good afternoon!"
    else:
        return "Good evening!"


pairs = [
    (r'hi|hello|hey|hey there|hola', [
        f'{get_greeting()} Welcome to the Library Assistant! How can I help you today?']),

    (r'what is your name\?|who are you\?', [
        'I am your friendly Library Assistant chatbot!']),

    (r'how are you\?|how\'s it going\?', [
        'I am doing well, thank you for asking! How can I assist you today?']),

    (r'(what|tell me) (is|do you have) (available|on the shelf) (books|novels)\?', [
        'We have a wide range of books, from fiction to non-fiction, history, and science. Can I help you find a specific genre?']),
   
    (r'(what|tell me) about (your|the) (membership|library card)\?', [
        'You can become a member by signing up at the front desk. Membership gives you access to borrowing books and exclusive library events.']),

    (r'(what|when) are your (hours|working hours)\?', [
        'We are open Monday to Friday, from 9 AM to 6 PM, and Saturday from 10 AM to 4 PM. We are closed on Sundays.']),
   
    (r'(when|what time) do you (open|close)\?', [
        'We open at 9 AM on weekdays and 10 AM on Saturdays. We close at 6 PM on weekdays and 4 PM on Saturdays.']),

    (r'can I borrow a book\?|how do I borrow a book\?', [
        'You can borrow books by becoming a member and checking out at the front desk. What book are you interested in?']),

    (r'bye|goodbye|see you later\?', [
        'Goodbye! Hope to see you soon at the library. Have a great day!']),

    (r'(.*)', [
        'Sorry, I didn\'t quite catch that. Could you please clarify or ask about our book collection, membership, or hours?'])
]

chatbot = Chat(pairs, reflections)

print("Chatbot: Hi, welcome to the Library Assistant! Type 'bye' to exit.")
while True:
    user_input = input("You: ")
    if user_input.lower() == 'bye':
        print("Chatbot: Goodbye!")
        break
    response = chatbot.respond(user_input)
    print(f"Chatbot: {response}")
