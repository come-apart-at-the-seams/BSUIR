from django.contrib import admin

# Register your models here.
from .models import Profiles, Topics, Added_Subs, Last_News, Last_Messages

@admin.register(Profiles)
class ProfilesAdmin(admin.ModelAdmin):
    list_display = ('name', 'tg_id', 'reg_date')
    # list_display = ('name', 'tg_id',)
    pass

@admin.register(Topics)
class ProfilesAdmin(admin.ModelAdmin):
    pass

@admin.register(Added_Subs)
class ProfilesAdmin(admin.ModelAdmin):
    pass

@admin.register(Last_News)
class ProfilesAdmin(admin.ModelAdmin):
    pass

@admin.register(Last_Messages)
class ProfilesAdmin(admin.ModelAdmin):
    pass

# @admin.register(Subs_Profile_Topic)
# class ProfilesAdmin(admin.ModelAdmin):
#     pass