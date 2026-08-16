const express = require('express');
const cors = require('cors');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3001;
const frontendDist = path.join(__dirname, '../frontend/dist');

const featured = {
  id: 'midnight-echoes',
  title: 'Midnight Echoes',
  artist: 'Neon Harbor',
  description: 'Late-night synth waves and dream-pop edits for your after-hours drive.',
  accent: 'linear-gradient(135deg, #1db954 0%, #04130a 100%)',
  listeners: '128K listeners',
  duration: '2h 18m'
};

const playlists = [
  { id: 'daily-mix-1', title: 'Daily Mix 1', owner: 'Made for you', tracks: 32, color: 'linear-gradient(135deg, #f59e0b, #ef4444)' },
  { id: 'chill-ambient', title: 'Chill Ambient', owner: 'Dream state', tracks: 58, color: 'linear-gradient(135deg, #38bdf8, #2563eb)' },
  { id: 'golden-hour', title: 'Golden Hour', owner: 'Sunset vibes', tracks: 24, color: 'linear-gradient(135deg, #f97316, #fb7185)' },
  { id: 'work-boost', title: 'Work Boost', owner: 'Focus mode', tracks: 41, color: 'linear-gradient(135deg, #10b981, #22c55e)' },
  { id: 'night-drive', title: 'Night Drive', owner: 'After dark', tracks: 19, color: 'linear-gradient(135deg, #7c3aed, #ec4899)' }
];

const library = [
  { id: 'liked-songs', title: 'Liked Songs', subtitle: '1,240 songs', color: 'linear-gradient(135deg, #1d4ed8, #60a5fa)' },
  { id: 'podcasts', title: 'Podcasts', subtitle: 'Fresh episodes', color: 'linear-gradient(135deg, #f97316, #fb7185)' },
  { id: 'albums', title: 'Albums', subtitle: 'Your favorites', color: 'linear-gradient(135deg, #22c55e, #16a34a)' },
  { id: 'artists', title: 'Artists', subtitle: 'Followed by you', color: 'linear-gradient(135deg, #a855f7, #ec4899)' }
];

const trending = [
  { id: 'song-1', title: 'Velvet Skies', artist: 'Aster Vale', duration: '3:42', genre: 'Dream Pop', color: 'linear-gradient(135deg, #1db954, #14532d)' },
  { id: 'song-2', title: 'City Lights', artist: 'North Echo', duration: '4:08', genre: 'Electronic', color: 'linear-gradient(135deg, #f59e0b, #b45309)' },
  { id: 'song-3', title: 'Summer Drift', artist: 'Kite Lane', duration: '3:19', genre: 'Indie', color: 'linear-gradient(135deg, #60a5fa, #1d4ed8)' },
  { id: 'song-4', title: 'Golden Thread', artist: 'Sol Aria', duration: '4:56', genre: 'Alt Pop', color: 'linear-gradient(135deg, #f472b6, #9d174d)' }
];

const catalog = [...playlists, ...library, ...trending].flatMap((item) => [
  { id: item.id, title: item.title, artist: item.owner || item.artist || 'Spotify', genre: item.genre || 'Playlist', kind: 'track' },
  { id: `${item.id}-alt`, title: item.title, artist: item.owner || item.artist || 'Spotify', genre: item.genre || 'Collection', kind: 'album' }
]);

app.use(cors());
app.use(express.json());

app.get('/api/health', (req, res) => {
  res.json({
    status: 'ok',
    message: 'Spotify clone backend is running.',
    timestamp: new Date().toISOString()
  });
});

app.get('/api/featured', (req, res) => {
  res.json(featured);
});

app.get('/api/playlists', (req, res) => {
  res.json(playlists);
});

app.get('/api/library', (req, res) => {
  res.json(library);
});

app.get('/api/trending', (req, res) => {
  res.json(trending);
});

app.get('/api/search', (req, res) => {
  const query = (req.query.q || '').trim().toLowerCase();

  if (!query) {
    return res.json({ query: '', results: [] });
  }

  const results = catalog.filter((item) => {
    const title = item.title.toLowerCase();
    const artist = item.artist.toLowerCase();
    const genre = item.genre.toLowerCase();
    return title.includes(query) || artist.includes(query) || genre.includes(query);
  });

  return res.json({ query, results: results.slice(0, 8) });
});

app.get('/api/album/:id', (req, res) => {
  const item = trending.find((track) => track.id === req.params.id) || playlists.find((playlist) => playlist.id === req.params.id);

  if (!item) {
    return res.status(404).json({ error: 'Album or playlist not found' });
  }

  return res.json({
    ...item,
    release: 'Fresh picks',
    year: 2026
  });
});

if (fs.existsSync(frontendDist)) {
  app.use(express.static(frontendDist));

  app.get('*', (req, res) => {
    if (req.path.startsWith('/api')) {
      return res.status(404).json({ error: 'API route not found' });
    }

    return res.sendFile(path.join(frontendDist, 'index.html'));
  });
}

app.listen(PORT, () => {
  console.log(`Spotify clone backend running on http://localhost:${PORT}`);
});
