import os
from PIL import Image

def create_animated_gif(folder_path, output_filename="animation.gif", duration_ms=100):
    """
    Creates an animated GIF from a sequence of PNG files in a folder.

    Args:
        folder_path (str): The path to the folder containing the PNGs.
        output_filename (str): The desired name for the output GIF file.
        duration_ms (int): The display duration for each frame, in milliseconds.
                           (e.g., 100ms = 10 frames per second).
    """

    # 1. Get all PNG files, sorted numerically
    # We use a custom sorting key to ensure '1.png' comes before '10.png'
    # and not after as a standard string sort would do.
    # The '1' through '200.png' pattern makes this easy.
    image_files = [f for f in os.listdir(folder_path) if f.endswith('.png')]
    image_files.sort(key=lambda x: int(os.path.splitext(x)[0]))

    if not image_files:
        print("Error: No PNG files found in the specified folder.")
        return

    # 2. Load all images into a list
    print(f"Found {len(image_files)} images. Loading frames...")
    frames = []

    # Use os.path.join to create the full path for each image
    for file_name in image_files:
        full_path = os.path.join(folder_path, file_name)
        try:
            img = Image.open(full_path)
            # It's generally best practice to convert to 'RGB' or 'P' mode for GIF creation
            # If your PNGs have transparency, you might need more complex handling.
            frames.append(img.convert('RGB'))
        except Exception as e:
            print(f"Could not open or process file {file_name}: {e}")

    # 3. Save the frames as an animated GIF
    if frames:
        print(f"Creating GIF: {output_filename}...")

        # Save the first frame and append the rest
        frames[0].save(
            output_filename,
            format='GIF',
            append_images=frames[1:],  # Append all images after the first one
            save_all=True,             # Essential for saving a sequence
            duration=duration_ms,      # Frame duration in milliseconds
            loop=0                     # 0 means the GIF loops forever
        )
        print(f"✅ GIF successfully created and saved as **{output_filename}**!")
    else:
        print("Error: No frames were successfully loaded.")

# --- Configuration ---
# Set the name of the folder containing your '1.png' through '200.png' files
PNG_FOLDER_NAME = "imgs"
OUTPUT_GIF = "output_animation.gif"
FRAME_DURATION = 43# 50 milliseconds per frame (20 frames per second)
# ---------------------

if __name__ == "__main__":
    # Create the target folder name path relative to the script's location
    # current_directory = os.path.dirname(os.path.abspath(__file__))
    # target_folder_path = os.path.join(current_directory, PNG_FOLDER_NAME)

    # Note: You may need to replace 'my_png_folder' with the actual name of your folder.
    create_animated_gif(
        folder_path="imgs",
        output_filename=OUTPUT_GIF,
        duration_ms=FRAME_DURATION
    )
