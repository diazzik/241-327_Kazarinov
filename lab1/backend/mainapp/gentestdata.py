import random
from faker import Faker
from .models import Restaurant
from django.db import transaction

fk = Faker()

def gentestdata():
    with transaction.atomic():
        for _ in range(100):
            r = Restaurant()
            r.name = fk.company()
            r.address = fk.address()
            r.cuisine = random.choice(['Italian', 'Japanese', 'Polish', 'Indian'])
            r.rating = round(random.uniform(1, 5), 1)
            r.is_open = random.choice([True, False])
            r.save()

    print("OK gentestdata()")