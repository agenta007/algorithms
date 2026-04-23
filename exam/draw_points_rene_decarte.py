import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator

def draw_cartesian_space(points, title="Points in Cartesian Space", filename="output.png"):
    x_coords = [point[0] for point in points]
    y_coords = [point[1] for point in points]

    fig, ax = plt.subplots(figsize=(10, 10))

    # Чертане на контурите (линиите)
    ax.plot(x_coords, y_coords, color='blue', linewidth=2, zorder=2, label="Контур")
    # Чертане на самите точки
    ax.scatter(x_coords, y_coords, color='red', s=50, zorder=3, label="Върхове")

    # Анотации с координати
    for (x, y) in points:
        ax.annotate(f'({x}, {y})', (x, y), textcoords="offset points", xytext=(0, 10), ha='center', fontsize=8)

    # Настройка на координатната система
    ax.spines['left'].set_position('zero')
    ax.spines['bottom'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')

    # ВАЖНО: Настройка на мрежата през 1 единица
    ax.xaxis.set_major_locator(MultipleLocator(1))
    ax.yaxis.set_major_locator(MultipleLocator(1))
    ax.grid(True, which='both', linestyle='--', alpha=0.5, zorder=0)

    # Граници на графиката (малко по-широки от точките за видимост)
    ax.set_xlim(-1, 11)
    ax.set_ylim(-1, 11)

    ax.set_aspect('equal')
    plt.title(title, pad=20)
    plt.legend()
    plt.savefig(filename)
    plt.close()

def main():
    # Точки от вашия пример
    day1_points = [(0, 0), (4, 0), (4, 6), (6, 6), (6, 0), (10, 0)]
    day2_points = [(0, 10), (4, 10), (4, 6), (6, 6), (6, 10), (10, 10)]

    draw_cartesian_space(day1_points, title="Силует - Ден 1 (Мрежа 1x1)", filename="day1_contour.png")
    draw_cartesian_space(day2_points, title="Силует - Ден 2 (Мрежа 1x1)", filename="day2_contour.png")