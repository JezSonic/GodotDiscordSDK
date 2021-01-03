#ifndef USERS_H_
#define USERS_H_

#include "discord.h"
#include "core.h"

#include "discord_game_sdk.h"

#include <gdnative_api_struct.gen.h>

void *user_constructor(godot_object *p_instance, struct Library *p_lib);
void user_destructor(godot_object *p_instance, struct Library *p_lib,
                     struct DiscordUser *p_user);

godot_variant user_get_id(godot_object *p_instance, struct Library *p_lib,
                          struct DiscordUser *p_user);
void user_set_id(godot_object *p_instance, struct Library *p_lib,
                 struct DiscordUser *p_user,
                 godot_variant *p_id);

godot_variant user_get_username(godot_object *p_instance, struct Library *p_lib,
                                struct DiscordUser *p_user);
void user_set_username(godot_object *p_instance, struct Library *p_lib,
                       struct DiscordUser *p_user,
                       godot_variant *p_username);

godot_variant user_get_discriminator(godot_object *p_instance, struct Library *p_lib,
                                     struct DiscordUser *p_user);
void user_set_discriminator(godot_object *p_instance, struct Library *p_lib,
                            struct DiscordUser *p_user,
                            godot_variant *p_discriminator);

godot_variant user_get_avatar(godot_object *p_instance, struct Library *p_lib,
                              struct DiscordUser *p_user);
void user_set_avatar(godot_object *p_instance, struct Library *p_lib,
                     struct DiscordUser *p_user,
                     godot_variant *p_avatar);

godot_variant user_get_bot(godot_object *p_instance, struct Library *p_lib,
                           struct DiscordUser *p_user);
void user_set_bot(godot_object *p_instance, struct Library *p_lib,
                  struct DiscordUser *p_user,
                  godot_variant *p_bot);

void register_user(void *p_handle, struct Library *p_lib);

typedef struct UserManager
{
    struct IDiscordUserManager *internal;
    godot_object *object;

    struct Core *core;

    struct Library *lib;
} UserManager;

void *user_manager_constructor(godot_object *p_instance, struct Library *p_lib);
void user_manager_destructor(godot_object *p_instance, struct Library *p_lib,
                             struct UserManager *p_user_manager);

godot_variant user_manager_get_current_user(godot_object *p_instance, struct Library *p_lib,
                                            struct UserManager *p_user_manager,
                                            int p_num_args, godot_variant **p_args);

godot_variant user_manager_get_user(godot_object *p_instance, struct Library *p_lib,
                                    struct UserManager *p_user_manager,
                                    int p_num_args, godot_variant **p_args);

void register_user_manager(void *p_handle, struct Library *p_lib);

void DISCORD_API on_current_user_update(struct Core *p_core);

#endif