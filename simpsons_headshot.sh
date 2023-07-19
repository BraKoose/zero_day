#!bin/bash
convert simpsons.gifv simpsons_frame_%d.png


# Fn to display a frame
display_frame() {
    cat "$1"
    sleep 0.1  # Adjust the sleep time to control animation speed
}

display_frame "simpsons_frame_0.png"


#loop thru frames of gif
for frame in $(ls simpsons_frame_*.png | sort -V); do
    clear
    cat "$frame"
    sleep 0.1  # Adjust the sleep time to control animation speed
done

rm simpsons_frame_*.png
