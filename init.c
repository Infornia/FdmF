/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 20:43:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 22:48:23 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_key	set_event(int keycode, void (*event)(t_data *d))
{
	t_key	key;

	key.key_code = keycode;
	key.event = event;
	return (key);
}

void			init_events(t_data *d)
{
	d->key_event[0] = set_event(ESC, &ft_fdf_exit);
	d->key_event[1] = set_event(UP, &move_up);
	d->key_event[2] = set_event(DOWN, &move_down);
	d->key_event[3] = set_event(LEFT, &move_left);
	d->key_event[4] = set_event(RIGHT, &move_right);
	d->key_event[5] = set_event(ZOOM_IN, &more_zoom);
	d->key_event[6] = set_event(ZOOM_OUT, &less_zoom);
	d->key_event[7] = set_event(PEAK_UP, &more_peak);
	d->key_event[8] = set_event(PEAK_DOWN, &less_peak);
}
