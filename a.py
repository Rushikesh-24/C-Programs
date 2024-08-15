import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

# Create a figure and axis
fig, ax = plt.subplots(figsize=(10, 12))

# Add shapes and text to represent the flowchart
# Start
ax.add_patch(mpatches.Rectangle((3.5, 10.5), 3, 1, edgecolor='black', facecolor='lightgray'))
ax.text(5, 11, 'Start', ha='center', va='center')

# Input
ax.add_patch(mpatches.Rectangle((3.5, 9), 3, 1, edgecolor='black', facecolor='white'))
ax.text(5, 9.5, 'Input: A, B, Operation', ha='center', va='center')

# Decision: Check if Operation is Addition
ax.add_patch(mpatches.Rectangle((3.5, 7.5), 3, 1.5, edgecolor='black', facecolor='lightblue'))
ax.text(5, 8.25, 'Operation = Addition?', ha='center', va='center')

# Add arrows
ax.annotate('', xy=(5, 10.5), xytext=(5, 9.5), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(5, 9), xytext=(5, 8.25), arrowprops=dict(arrowstyle="->"))

# Decision for Addition path (yes)
ax.add_patch(mpatches.Rectangle((0.5, 6), 3, 1.5, edgecolor='black', facecolor='lightblue'))
ax.text(2, 6.75, 'Signed or Unsigned?', ha='center', va='center')

# Addition (Unsigned)
ax.add_patch(mpatches.Rectangle((0.5, 4.5), 3, 1, edgecolor='black', facecolor='lightgreen'))
ax.text(2, 5, 'Perform Binary Addition', ha='center', va='center')

# Addition (Signed)
ax.add_patch(mpatches.Rectangle((0.5, 3), 3, 1.5, edgecolor='black', facecolor='lightgreen'))
ax.text(2, 3.75, 'Check Sign Bit & Perform Addition/Subtraction', ha='center', va='center')

# Overflow check
ax.add_patch(mpatches.Rectangle((0.5, 1.5), 3, 1, edgecolor='black', facecolor='yellow'))
ax.text(2, 2, 'Check for Overflow', ha='center', va='center')

# Output Result (Addition)
ax.add_patch(mpatches.Rectangle((0.5, 0), 3, 1, edgecolor='black', facecolor='lightgray'))
ax.text(2, 0.5, 'Output Result', ha='center', va='center')

# Addition Path Arrows
ax.annotate('', xy=(5, 8.25), xytext=(2, 8.25), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(2, 6), xytext=(2, 5), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(2, 4.5), xytext=(2, 3.75), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(2, 3), xytext=(2, 2), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(2, 1.5), xytext=(2, 0.5), arrowprops=dict(arrowstyle="->"))

# Decision for Subtraction path (no)
ax.add_patch(mpatches.Rectangle((6.5, 6), 3, 1.5, edgecolor='black', facecolor='lightblue'))
ax.text(8, 6.75, 'Signed or Unsigned?', ha='center', va='center')

# Subtraction (Unsigned)
ax.add_patch(mpatches.Rectangle((6.5, 4.5), 3, 1, edgecolor='black', facecolor='lightgreen'))
ax.text(8, 5, 'Perform Binary Subtraction', ha='center', va='center')

# Subtraction (Signed)
ax.add_patch(mpatches.Rectangle((6.5, 3), 3, 1.5, edgecolor='black', facecolor='lightgreen'))
ax.text(8, 3.75, 'Check Sign Bit & Perform Addition/Subtraction', ha='center', va='center')

# Overflow check (Subtraction)
ax.add_patch(mpatches.Rectangle((6.5, 1.5), 3, 1, edgecolor='black', facecolor='yellow'))
ax.text(8, 2, 'Check for Overflow', ha='center', va='center')

# Output Result (Subtraction)
ax.add_patch(mpatches.Rectangle((6.5, 0), 3, 1, edgecolor='black', facecolor='lightgray'))
ax.text(8, 0.5, 'Output Result', ha='center', va='center')

# Subtraction Path Arrows
ax.annotate('', xy=(5, 8.25), xytext=(8, 8.25), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(8, 6), xytext=(8, 5), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(8, 4.5), xytext=(8, 3.75), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(8, 3), xytext=(8, 2), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(8, 1.5), xytext=(8, 0.5), arrowprops=dict(arrowstyle="->"))

# End
ax.add_patch(mpatches.Rectangle((3.5, -1.5), 3, 1, edgecolor='black', facecolor='lightgray'))
ax.text(5, -1, 'End', ha='center', va='center')

# End Arrows
ax.annotate('', xy=(2, 0), xytext=(5, -0.5), arrowprops=dict(arrowstyle="->"))
ax.annotate('', xy=(8, 0), xytext=(5, -0.5), arrowprops=dict(arrowstyle="->"))

# Hide axes
ax.axis('off')

# Save the diagram as an image
plt.savefig('/mnt/data/binary_addition_subtraction_flowchart.png')
plt.show()