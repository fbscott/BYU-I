import arcade

class DemoApp(arcade.Window):
    """demo app constructor"""
    
    def __init__(self, width, height):
        super().__init__(width, height)

        arcade.set_background_color(arcade.color.AMBER)

    def on_draw(self):
        """called when needed to draw window"""
        arcade.start_render()

        arcade.draw_rectangle_filled(100, 100, 50, 20, arcade.color.BLACK)

    def update(self, delta_time: float):
        """move things"""
        pass

window = DemoApp(500, 500)
arcade.run()
