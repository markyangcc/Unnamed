from PIL import Image

# Import images into memory
mask = Image.open('mask.png')
word = Image.open('word_matrix.png')


# Resize image to match both
resized_mask = mask.resize(word.size)

if resized_mask.size == word.size:
    print('Image size matched. Keep Running...')
else:
    print('Image size not matched.')
    exit()

# Add alpha parameter
resized_mask.putalpha(100)

# paste image
word.paste(resized_mask, (0, 0), resized_mask)

word.show()