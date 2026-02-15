import string
import nltk
from nltk.corpus import stopwords

nltk.download('stopwords')

text = "Hello! This is an example sentence, showing how text preprocessing works."

# Lowercasing
text = text.lower()

# Remove punctuation
text = text.translate(str.maketrans('', '', string.punctuation))

# Remove stopwords
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in text.split() if word not in stop_words]

processed_text = " ".join(filtered_words)
print(processed_text)
