import nltk
from nltk.corpus import gutenberg, reuters

# Download necessary resources (run once)
nltk.download('gutenberg')
nltk.download('reuters')

# --- Exploring Gutenberg Corpus ---
print("Available file IDs in the Gutenberg corpus:\n")
file_ids = gutenberg.fileids()
for file_id in file_ids:
    print("-", file_id)

# --- Exploring Reuters Corpus ---
print("\nAvailable categories in the Reuters corpus:\n")
categories = reuters.categories()
for category in categories[:20]:  # Showing only the first 20 to keep output short
    print("-", category)

# If you want to see all categories, remove [:20]
