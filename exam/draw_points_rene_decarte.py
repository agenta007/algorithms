import matplotlib.pyplot as plt

def draw_cartesian_space(points, title="Points in Cartesian Space"):
    """
    Draws a list of (x, y) points in a Cartesian coordinate system.
    """
    # Extract X and Y coordinates into separate lists
    x_coords = [point[0] for point in points]
    y_coords = [point[1] for point in points]

    # Create the figure and axis
    fig, ax = plt.subplots(figsize=(8, 8))

    # Set the actual window title
    fig.canvas.manager.set_window_title(title)

    # Scatter plot for the points
    ax.scatter(x_coords, y_coords, color='red', s=50, zorder=3, label="Given Points")

    # Annotate each point with its coordinates
    for (x, y) in points:
        ax.annotate(f'({x}, {y})', (x, y), textcoords="offset points", xytext=(8, 8), ha='center')

    # --- Setup the Cartesian (Descartes) Space ---

    # Move the left and bottom spines (axes) to the center (0,0)
    ax.spines['left'].set_position('zero')
    ax.spines['bottom'].set_position('zero')

    # Hide the top and right spines
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')

    # Ensure ticks are placed correctly
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')

    # Add a grid for better readability
    ax.grid(True, linestyle='--', alpha=0.6, zorder=0)

    # Set dynamic limits based on the points to ensure everything is visible
    max_val = max(max(abs(x) for x in x_coords), max(abs(y) for y in y_coords)) + 2

    # Using -2 instead of -max_val for the lower bounds so the all-positive
    # coordinates from your task are zoomed in properly while keeping the axes visible.
    ax.set_xlim(-2, max_val)
    ax.set_ylim(-2, max_val)

    # Make the X and Y axes have the same scale
    ax.set_aspect('equal')

    # Add a title to the graph itself
    plt.title(title, pad=20)

    # Note: plt.show() has been removed from here!

# --- Example Usage ---
if __name__ == "__main__":
    # First set of points (Day 1 Silhouette)
    N_points = [
        (0, 0),
        (4, 0),
        (4, 6),
        (6, 6),
        (6, 0),
        (10, 0),
    ]

    # Second set of points (Day 2 Silhouette)
    N_points_2 = [
        (0, 10),
        (4, 10),
        (4, 6),
        (6, 6),
        (6, 10),
        (10, 10)
    ]

    # Generate the first window
    draw_cartesian_space(N_points, title="Silhouette - Day 1")

    # Generate the second window
    draw_cartesian_space(N_points_2, title="Silhouette - Day 2")

    # Show both windows simultaneously
    plt.show()