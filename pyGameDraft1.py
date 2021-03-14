import PyGame

class Game:
    screen = None
    aliens = []
    
    def__init__(self, width, height):
        pygame.init()
        self.width = width
        self.height = height
        self.screen = pygame.display.set_mode((width,height))
        self.clock = pygame.time.Clock()
        done = False
        
        while not done:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    done = True
                    
        pygme.display.()
        self.clock.tick(60)
        self.screen.fill((0,0,0))
        
class Alien:
    def __init(self,game,x,y):
        self.x = x
        self.game = game
        self.y = display
        
    def draw(self):
        pygame.draw.rect(self.game.screen,(81,43,88),pygame.Rect(self.x,self.y,30,30))
    
    self.y += 0.05
    
alien = Alien(self,30,30)
alien.draw()

class Hero:
    def __init__(self,game,x,y):
        self.x = x
        self.game = game
        self.y = y
    
    def draw(self):
        pygame.draw.rect(self.game.screen,(210,250,251),pygame.Rect(self.x,self.y,8,5))
        
hero = Hero(self, width/2, height-20)
    
hero.draw()
    
class Generator:
    def __init__(self,game):
        margin = 30
        width = 50
        for x in range(margin, game.width - margin, width):
            for y in range(margin, int (game.height/2),width):
                game.aliens.append(Alien(game,x,y))
generator = Generator(self)

for alien in self.aliens:
    alien.draw()
    
class Rocket:
    def __init__(self,game,x,y):
        self.x = x
        self.y = y
        self.game = game
        
    def draw(self):
        pygame.draw.rect(self.game.screen,(254,52,110),pygame.Rect(self.x,self.y,2,4))
        self.y -= 2
        
if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
    self.rockets.append(Rocket(self, hero.x, hero.y))
    
for rocket in self.rockets:
    rocket.draw()
    
def checkCollision(self,game):
    for rocket in game.rockets:
        if (rocket.x < self.x + self.size and
        rocket.x > self.x - self.size and
        rocket.y < self.y + self.size and
        rocket.y > self.y - self.size):
            
            game rockets.remove(rocket)
            game.aliens.remove(self)
alien.checkCollision(self)

pressed - pygame.key.get_pressed()
if pressed[pygame.K_LEFT]:
    hero.x -= 2 if hero.x > 20 else 0
elif pressed [pygame.K_RIGHT]:
    hero.x += 2 if hero.x < width-20 else width-20
    
if len(self.aliens) == 0:
    self.displayText("VICTORY")
if (alien.y > height):
    self.lost = True
    self.displayText("DEFEAT")
if not self.lost: hero.draw()

if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE and not self.lost:
    self.rockets.append(Rocket(self,hero.x,hero.y))